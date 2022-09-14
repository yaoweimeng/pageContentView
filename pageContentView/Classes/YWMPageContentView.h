//
//  TYTPageContentView.h
//  TytCars
//
//  Created by teyuntong on 2022/8/4.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class YWMPageContentView;
@protocol TYTPageContentViewDelegate <NSObject>
@optional
/**
 TYTPageContentView开始滑动
 @param contentView TYTPageContentView
 */
- (void)TYTContentViewWillBeginDragging:(YWMPageContentView *)contentView;
/**
 TYTPageContentView滑动调用
 @param contentView TYTPageContentView
 @param startIndex 开始滑动页面索引
 @param endIndex 结束滑动页面索引
 @param progress 滑动进度
 */
- (void)TYTContentViewDidScroll:(YWMPageContentView *)contentView startIndex:(NSInteger)startIndex endIndex:(NSInteger)endIndex progress:(CGFloat)progress;

/**
 TYTPageContentView结束滑动
 @param contentView TYTPageContentView
 @param startIndex 开始滑动索引
 @param endIndex 结束滑动索引
 */
- (void)TYTContenViewDidEndDecelerating:(YWMPageContentView *)contentView startIndex:(NSInteger)startIndex endIndex:(NSInteger)endIndex;

/**
 scrollViewDidEndDragging
 @param contentView TYTPageContentView
 */
- (void)TYTContenViewDidEndDragging:(YWMPageContentView *)contentView;

@end
@interface YWMPageContentView : UIView
/**
 对象方法创建TYTPageContentView
 @param frame frame
 @param childVCs 子VC数组
 @param parentVC 父视图VC
 @param delegate delegate
 @return TYTPageContentView
 */
- (instancetype)initWithFrame:(CGRect)frame childVCs:(NSArray *)childVCs parentVC:(UIViewController *)parentVC delegate:(id<TYTPageContentViewDelegate>)delegate;

@property (nonatomic, weak) id<TYTPageContentViewDelegate>delegate;

/**
 设置contentView当前展示的页面索引，默认为0
 */
@property (nonatomic, assign) NSInteger contentViewCurrentIndex;

/**
 设置contentView能否左右滑动，默认YES
 */
@property (nonatomic, assign) BOOL contentViewCanScroll;
@end

NS_ASSUME_NONNULL_END
