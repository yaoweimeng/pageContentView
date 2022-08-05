//
//  TYTTestViewController.m
//  TytCars
//
//  Created by teyuntong on 2022/8/4.
//

#import "YWMTestViewController.h"
#import "YWMChildViewController.h"
#import "YWMPageContentView.h"
@interface YWMTestViewController ()<TYTPageContentViewDelegate>
@property (nonatomic, strong) YWMPageContentView *pageContentView;

@end

@implementation YWMTestViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSMutableArray *childVCs = [[NSMutableArray alloc] init];
    for (int i = 0; i < 10; i++) {
        YWMChildViewController *vc = [[YWMChildViewController alloc]init];
        [childVCs addObject:vc];
    }
    self.pageContentView = [[YWMPageContentView alloc]initWithFrame:CGRectMake(0, 114, CGRectGetWidth(self.view.bounds), CGRectGetHeight(self.view.bounds) - 90) childVCs:childVCs parentVC:self delegate:self];
    self.pageContentView.contentViewCurrentIndex = 1;
    [self.view addSubview:_pageContentView];
    
}

@end
